---
title: 漫画：什么是红黑树
category: 算法
tags: 
  - 树
  - baijiahao.baidu.com
created_at: 2020-04-28 09:46:00
original_url: https://baijiahao.baidu.com/s?id=1641940303518144126&wfr=spider&for=pc
---


# 漫画：什么是红黑树

[![到百度首页](assets/1588038360-167de233949df2ccc4331746c45df11f.png "到百度首页")](https://www.baidu.com/)

[百度首页](https://www.baidu.com/)

[wiseheadchen](http://i.baidu.com/)

## 漫画：什么是红黑树

![](assets/1588038360-a110eb127258090541094e2f4d8bbcdb.jpg)

脚本之家

发布时间：19-08-1609:27

![](assets/1588038360-f37fa8ba2e7a82596a6fcfc0be06c58b.jpeg)

![](assets/1588038360-e7e3703e683ac0541e44c100197369c0.jpeg)

![](assets/1588038360-7f5ef557e9b1ea548af0e4014b465355.jpeg)

![](assets/1588038360-ac442ef6aa523b288efcde07bf4c4798.jpeg)

![](assets/1588038360-3870f791c7b84d84856595503c9e347e.jpeg)

下面为标准的二叉排序树

![](assets/1588038360-d868d7b7cea2982ab00eb68f13c22c96.jpeg)

![](assets/1588038360-8d0765ee45b200c6a45cf5b115dfc33e.jpeg)

初始状态

![](assets/1588038360-0f839cf437c12f49a77dd53818899b2c.jpeg)

其实想要搜索值为226的节点很简单，搜索动画过程如下：

![](assets/1588038360-a6447cf1f87598473dd6c32ec40aefce.gif)

![](assets/1588038360-60ea8f3f4d10774f2d8b804fe2132504.jpeg)

![](assets/1588038360-2686c6a01652c50529491a79b72df28b.jpeg)

![](assets/1588038360-408e600df6db79b809e799264f048c39.jpeg)

![](assets/1588038360-bd90ef4c1508dfc5004f7ae99178ff81.jpeg)

![](assets/1588038360-cba259754f26d1bdf8310716bbbf65de.jpeg)

这样不行！

这是个病！

得治！

![](assets/1588038360-7ec518cf629d5a77c639611d6c69f658.jpeg)

![](assets/1588038360-0b4e87e37e7bd5eb206b68365205060a.jpeg)

![](assets/1588038360-2061cfac469a2cc584224f5314c3ae7e.jpeg)

红黑树就是一种平衡的二叉查找树，说他平衡的意思是他不会变成“瘸子”，左腿特别长或者右腿特别长。除了符合二叉查找树的特性之外，还具体下列的特性：

1\. 节点是红色或者黑色

2\. 根节点是黑色

3\. 每个叶子的节点都是黑色的空节点（NULL）

4\. 每个红色节点的两个子节点都是黑色的。

5\. 从任意节点到其每个叶子的所有路径都包含相同的黑色节点。

下面为标准的红黑树，阿广建议大家对照下面的图理解上边写的红黑树的性质哦~

![](assets/1588038360-3504202fcf5c88e3fff227bfeb2f1d5d.jpeg)

（黑色的NULL节点可忽略）

![](assets/1588038360-7d447199d57630ce05738b797e21401e.jpeg)

![](assets/1588038360-c3d0dc3fb675ae955f93ffd1dfaf6859.jpeg)

例如上面标准的红黑树，插入值为12的节点。

![](assets/1588038360-1d593280edfbfc2f1f6ff07163262847.jpeg)

插入之后发现仍然满足红黑树的要求！

但是如果插入值为21的节点呢？

如下图所示：

![](assets/1588038360-cfa41bd652d2c211325eac362dacf532.jpeg)

![](assets/1588038360-851894d3810bf85049674768edf91e4a.jpeg)

![](assets/1588038360-98657d8c8b3cebb893b70a1f48626fed.jpeg)

先来看一下变色！

为了符合红黑树的规则，会把节点红变黑或者黑变红。下图展示的是红黑树的部分，需要注意节点25并非根节点。因为21和22链接出现红色，不符合规则4，所以把22红变黑：

![](assets/1588038360-c3fd663b56d76a38aa25be02fe2acba6.jpeg)

但这样还是不符合规则5，所以需要把25黑变红，看下图：

![](assets/1588038360-8420d4643df5a44afcf40c5ebd9f878d.jpeg)

![](assets/1588038360-a3c2e56e47177f8b03cc7de341cbb176.jpeg)

![](assets/1588038360-29e4a102886d5bad5995ef2b85712710.jpeg)

![](assets/1588038360-2d7fa32464415e155b80cf52b4551594.jpeg)

![](assets/1588038360-797d3c1be00b77d5c3d820ba11d67e4f.jpeg)

![](assets/1588038360-4c7a386a937082b4ead9bacab5401f83.jpeg)

![](assets/1588038360-d8133a40366505a9ee5000c173727bc6.jpeg)

接下来先讲一下什么是左旋转！通过动画举个例子吧！

![](assets/1588038360-3958cde4548f33c25ee255e64d9ce510.gif)

![](assets/1588038360-3cf3f210660ef458e005b8f7b9054846.gif)

左旋转思想示意图如下

![](assets/1588038360-e8f5f3d1ea1126062711e7d985656eef.jpeg)

通俗点讲一下，可以看下面的左旋转静态示意图

![](assets/1588038360-e1d9caa87bcd1b88fb04fe547e37784c.jpeg)

按照左旋转，对上边已经变色完成之后图进行左旋转。

![](assets/1588038360-f99c0b0ddd0718d9eee8b8a4bf732caf.jpeg)

![](assets/1588038360-8559f9f2f2d0c83450d56a72d5c695dd.jpeg)

![](assets/1588038360-665d641a2a1bc0773c2c5712875a2e83.jpeg)

![](assets/1588038360-6ee5d66c604e441887d6865b7060b15d.jpeg)

![](assets/1588038360-2f08d557dc9c3ec5ae12c9777dc7ccaa.jpeg)

![](assets/1588038360-fc20dc9c33e9b8ac6ba80f09fad00458.jpeg)

![](assets/1588038360-c0405c4829132d4bb86e5ebff0f7d49f.gif)

![](assets/1588038360-b34411ad893d836010d26bf23932eafe.gif)

可见右旋转的思想总结如下：

![](assets/1588038360-ea2b46efefcc31542d13d093f5187573.jpeg)

通俗点讲一下，可以看下面的右旋转静态示意图

![](assets/1588038360-43299b286c93417fa372cb511655bbb2.jpeg)

接下来，对上边经过左旋转之后的图进行右旋转。

![](assets/1588038360-872de0eb4363891752fd5eeebf3d809d.jpeg)

![](assets/1588038360-f7819c75edf4833a20f29f92ce903ffc.jpeg)

![](assets/1588038360-18f8876a22108aeabde6a525df7ca496.jpeg)

![](assets/1588038360-67a681dee3f49f930363b26de841307e.jpeg)

![](assets/1588038360-a15c06213463a57c5147df3641b7d6dc.jpeg)

![](assets/1588038360-eef917422dcb459d76f651ea7dd62831.jpeg)

![](assets/1588038360-ddbfbc4d3b5242d2b3a043f7497923b7.jpeg)

![](assets/1588038360-ff348dfa2fe515612aaf9d0d8d7fa7c1.jpeg)

![](assets/1588038360-a8cb961068b50939462797ef5f1605b3.jpeg)

人生像红黑树一样，总是需要某种平衡

一边是给予，一边是接受

一边是付出，一边是得到

一边是耕耘，一边是收获

一边是物质，一边是精神

阿广你年过二十而未立

置身于五光十色的世俗社会

我希望阿广都能铭记

一个古老但不失色彩的道理！

“活得简单才能活得自由”

因为舍得，所以淡泊

因为朴素，难以物役

所以保持精神和内在的富有

才是平衡的前提

## 相关文章

*   ### [“TZ301-1”钻井平台天津起运远赴墨西哥湾](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9053268615763380627%22%7D&n_type=1&p_from=4)
    
    [![](assets/1588038360-628392fa88e8ba9fc56f326513f3b745.jpg)](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9053268615763380627%22%7D&n_type=1&p_from=4)
    
*   ### [中国成全球最大的服装生产和出口国2020年中国服装行业出口现状分析（图）](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9212479162185349618%22%7D&n_type=1&p_from=4)
    
    [![](assets/1588038360-66afd3142c52e54939865450622a7508.jpg)](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9212479162185349618%22%7D&n_type=1&p_from=4)
    
*   ### [中国石化西南局天然气创新高 年产已超20亿方](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9724361486360041648%22%7D&n_type=1&p_from=4)
    
    [![](assets/1588038360-832ca9dffc5c1bbad320a6380e2744ee.jpg)](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9724361486360041648%22%7D&n_type=1&p_from=4)
    
*   ### [创业板注册制来了！首批企业何时亮相？一文速览改革重点、A股影响及受益板块](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9855245641156551824%22%7D&n_type=1&p_from=4)
    
    [![](assets/1588038360-d44a2ddfcf392957a20d7109146dc795.jpg)](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_9855245641156551824%22%7D&n_type=1&p_from=4)
    
*   ### [疫情防控不放松 浙江扫黑除恶再加速](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_8559393534614727855%22%7D&n_type=1&p_from=4)
    
    [![](assets/1588038360-49d0265e8d2a115dfa4eaa287e788926.jpg)](https://mbd.baidu.com/newspage/data/landingsuper?context=%7B%22nid%22%3A%22news_8559393534614727855%22%7D&n_type=1&p_from=4)
    

[设为首页](https://www.baidu.com/cache/sethelp/index.html)© Baidu [使用百度前必读](https://www.baidu.com/duty/) [意见反馈](http://jianyi.baidu.com/) 京ICP证030173号 ![](assets/1588038360-662a8fc8dd944d9325b91ce796793427.png)

[京公网安备11000002000001号](http://www.beian.gov.cn/portal/registerSystemInfo?recordcode=11000002000001)

---------------------------------------------------


原网址: [访问](https://baijiahao.baidu.com/s?id=1641940303518144126&wfr=spider&for=pc)

创建于: 2020-04-28 09:46:00

目录: 算法

标签: `树`, `baijiahao.baidu.com`

