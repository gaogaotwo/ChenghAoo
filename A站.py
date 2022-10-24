# -*- coding:utf-8 -*-
"""
    爬虫案例流程
    1，明确需求，需要爬取那些信息？
    2，分析信息来自与哪里？
        开发者工具，抓包分析，数据包来源与哪里？
            视频 m3u8,分片段模式
            分析网页源代码进行分析
            想要视频内容 -------》 分片段ts文件 ---------》 m3u8文件里面 ----》 网页源代码
            headers ---->  cookies host referer ua
    3，
    代码具体实现：
      1，发送请求，网站url发起请求
      2，获取数据，获取服务器相应html数据，并通过re模块正则表达式匹配
      3，解析数据，提取我们想要的,m3u8 Ts,url请求链接

      4，发送请求 m3u8url 获取 Ts数据
      5，获取数据
      6，解析数据
      7，保存数据
"""
import requests
import re
import json
from pathlib import Path
import time
# 伪装浏览器 headers
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36"
}
vedio_dir = Path('./vedio')
vedio_dir.mkdir(exist_ok=True)

def afun_init(url):
    # 发送请求，获取数据
    response = requests.get(url=url, headers=headers)
    # 提取视频标题
    title = re.findall('"title":"(.*?)"', response.text)[1]
    print(title)
    # 获取m3u8链接，获取Ts数据
    u3u8_str = re.findall('window.pageInfo = window.videoInfo = (.*?)};', response.text)[0]
    u3u8_str += '}'
    # 字符串类型数据
    # 根据键值对取m3u8url
    u3u8_json = json.loads(u3u8_str)
    # 二次转换
    # backupUrl 视频m3u8链接 对应的视频画质
    m3u8_url = \
    json.loads(u3u8_json['currentVideoInfo']['ksPlayJson'])['adaptationSet'][0]['representation'][0]['backupUrl'][0]
    print(m3u8_url)
    # 获取m3u8链接完毕，获取Ts链接全部文件
    m3u8_data = requests.get(url=m3u8_url, headers=headers).text
    # 解析数据，获取Ts文件
    # 拆分分割符号
    m3u8_data = re.sub('#E.*', '', m3u8_data).split()
    return m3u8_data, title

if __name__ == '__main__':
    print("A站视频下载器|单线程版")
    while True:
        print("注: url值为 0 退出系统")
        url = input("请输入视频url: ")
        if url == "0":
            break
        start_time = time.time()
        m3u8_data = afun_init(url)[0]
        title = afun_init(url)[1]
        # for 循环遍历 ts 内容
        print(m3u8_data)
        for ts in m3u8_data:
            ts_url = 'https://ali-safety-video.acfun.cn/mediacloud/acfun/acfun_video/' + ts
            # 获取视频二进制数据
            ts_content = requests.get(url=ts_url, headers=headers, timeout=5).content
            # 若视频标题不符合规范将会报错
            with open('./vedio/' + m3u8_data[0][0:5] + '.mp4', 'ab') as f:
                f.write(ts_content)
                print(ts_url)
        end_time = time.time()
        print("视频下载时间", end_time - start_time)
        print("下载完毕\n")
