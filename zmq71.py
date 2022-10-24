# -*- coding:utf-8 -*-
import requests
import re
import json
from tqdm import tqdm
import time

# 请输入你想要下载视频key值
zmq7_key = input("请输入视频Key值: ")
start_time = time.time()
zmq7_u = '674448b1-41b1-4b58-a08a-327d0819da68'
zmq7_fp = 'e23f2769a8bc1ff481f3b03a2f563382'
headers = {
    'Referer': 'https://zmq71.com/',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36'
}
# 请求 api_url获取到 m3u8_url的值
m3u8_api_url = 'https://a1.zimu73.com/api/resource/get?lang=en&v=' + zmq7_key + '&u=' + zmq7_u + '&fp=' + zmq7_fp
m3u8_l = requests.get(url=m3u8_api_url, headers=headers).json()['data']['v']['l']
zmq7_web = 'https://ns{}.zmq71.site/'.format(m3u8_l)
m3u8_url = zmq7_web + requests.get(url=m3u8_api_url, headers=headers).json()['data']['v']['url']
print(m3u8_url)
# 选择集群
m3u8_date = m3u8_url.split('/')[5]

# 获取 m3u8_data 数据
m3u8_url_data = requests.get(url=m3u8_url, headers=headers).text
# 正则表达式替换操作
m3u8_url_data = re.sub('#E.*', '', m3u8_url_data).split()
# print(m3u8_url_data)
for ts in tqdm(m3u8_url_data):
    # 字符串分割一定要注意未知的空格
    ts_url = zmq7_web + 'storage/videos/' + m3u8_date + '/' + ts
    # print(ts_url)
    ts_content = requests.get(url=ts_url, headers=headers, verify=False).content
    with open('./vedio/' + m3u8_url_data[0].split('.')[0] + '.mp4', 'ab') as f:
        f.write(ts_content)
print("下载完毕")

end_time = time.time()
print("程序执行时间 ", end_time - start_time)
