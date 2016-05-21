# 豆瓣FM第三方开发

* 以下为linux系统中，qt作为开发工具下的第三方开发，积累了前人及网上的一些资源。

-------------------


##1、获取频道
- **URL**: https://www.douban.com/j/app/radio/channels
- **Method**: GET
- **Response**:`(application/json)`

 ####获取成功
``` json
{
 sss
}
.
```
 解析json数据，获得所需要的元素。


--------------------
##2、获取歌曲
- **URL**:https://www.douban.com/j/app/radio/people?app_name=radio_android&version=100&type=b&channel="
- **Method**: GET
- **Arguments**:


 ####新建成功
``` json
{
    sss
}
.
```
 解析json数据，获得所需要的元素。


----------------------------------------------
##3、获取歌词
- **URL**: https://api.weipan.cn/2/metadata/sandbox/?
- **Method**: POST
- **Arguments**:


 ####获取成功
``` json
{
    sss
}
.
```
 解析json数据，获得所需要的元素。
