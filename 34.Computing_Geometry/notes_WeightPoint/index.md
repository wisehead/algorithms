---
title: 计算一个多边形的重心点坐标 - 简书
category: default
tags: 
  - www.jianshu.com
created_at: 2020-12-23 14:47:24
original_url: https://www.jianshu.com/p/39ef232ad531
---

# 计算一个多边形的重心点坐标

[![](assets/1608706044-3d0a7160ae35fbd7c98cc542bda1d99f.png)](https://www.jianshu.com/u/200ff3d414b8)

[hanson21](https://www.jianshu.com/u/200ff3d414b8)关注

0.2722019.05.11 17:02:13字数 1,652阅读 5,253

## 背景介绍与问题分析

在之前的 [《如何判断一个多边形是否合法》](https://www.jianshu.com/p/1cd7af0d6524) 一文中有提到，用无人机规划飞行路线前，往往需要框选一个多边形的区域。

而在地图控件上显示这个多边形区域时，往往会遇到这样一个需求：需要把所要测绘的多边形区域移动到地图中心。

实现这个需求的基本思路就是：获取到多边形区域的重心点坐标，然后利用地图控件的 `setCenter`方法，就可以把地图的显示中心移动到多边形区域重心了。那么问题来了，如何求出一个多边形的重心点坐标呢？

> 这里所说的重心，也常常叫几何中心

这里首先给出一个公式:

平面多边形 ![X](assets/1608706044-92af9e062abd6259eb716a4f106f94c3.svg) 可以被剖分为 n个有限的简单图形 ![X_1,X_2,....X_n](assets/1608706044-3362d193e823853bb18ba39a13c398f1.svg)，这些简单图形的重心点为 ![C_1](assets/1608706044-1d43d2feda6fa2d8f2f052efcac1575f.svg)，面积为 ![A_1](assets/1608706044-cd978a074152ad7b607d1d959dd30a38.svg)，那么这个平面多边形的重心点坐标为 ![(C_x,C_y)](assets/1608706044-d6d7b4bae242398b2f4cffb27c7c9400.svg)  
![C_x = \frac{\sum C_{i_x} A_i}{\sum A_i}, C_y = \frac{\sum C_{i_y} A_i}{\sum A_i}](assets/1608706044-308bc679e4d6c0aa57bf3bf1533ed7d7.svg)

> 公式参考: [维基百科](https://links.jianshu.com/go?to=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FCentroid%23Centroid_of_polygon)

一般来说我们可以给多边形进行三角剖分，而 ![\sum{A_i}](assets/1608706044-82fdf8bbd9840fdad6aecb452c157e60.svg) 即为多边形的总面积，那么这个公式可以理解为：

多边形重心横坐标 = 多边形剖分的每一个三角形重心的横坐标 \* 该三角形的面积之和 / 多边形总面积

多边形重心纵坐标 = 多边形剖分的每一个三角形重心的纵坐标 \* 该三角形的面积之和 / 多边形总面积

所以这里就把问题拆分成了三个小问题：

*   求每个剖分出来的三角形的重心。
*   求每个剖分出来的三角形的面积。
*   求多边形的面积。

## 算法解析

### 1\. 求三角形的重心

![](assets/1608706044-2df08fb3cbe8efef46f83a4e2fdd01d5.png)

三角形重心

  
三角形的重心：三条中线的交点。其中重心到其中一个顶点的距离是重心到该顶点对边中点的距离的2倍。  
即：GC = 2 \* GP，也就是说重心坐标在 CP 线段上距离 AB 的中点 P 的 1/3 处。  
假设 A,B,C 三点的坐标为：  

![A:(x_1,y_1),B:(x_2,y_2),C:(x_3,y_3)](assets/1608706044-97de8395eb1dcf8fc78c639c57c5392d.svg)

那么通过简单坐标计算，可以得出其重心坐标为 ![(x,y)](assets/1608706044-5188869f10b9c5be194f00ca708d8bf5.svg)  
![x = \frac{(x_1+x_2+x_3)}{3} , y = \frac{(y_1+y_2+y_3)}{3}](assets/1608706044-a0a0b265a6a8640435eee26b71c53100.svg)

### 2\. 求三角形面积

计算三角形的面积，我们这里利用 `向量积`来计算，我们知道平面中的两个向量的叉乘的模等于以这两个向量为边的平行四边形的面积，那么以这个两个向量为边的三角形，则是这个平行四边形的面积的一半。

> 参考：[向量叉积](https://links.jianshu.com/go?to=https%3A%2F%2Fzh.wikipedia.org%2Fwiki%2F%25E5%258F%2589%25E7%25A7%25AF)

![](assets/1608706044-0f84af141392d5e4eab1b2c2119573c1.png)

如上图，已知平面上两点 ![A:(x_1,y_1),B(x_2,y_2)](assets/1608706044-b2eea0f4cd6dbe89a381329c00541de1.svg) ，以 A，B和坐标原点 ![P(0,0)](assets/1608706044-9be7bcbc7f63ca9321d5b61f7daf532a.svg) 构成的三角形的面积 S 为：  
![S=\frac{\vec{PB}\times\vec{PA}}{2} = \frac{x_2y_1 - x_1y_2 }{2}](assets/1608706044-ef5e476dd4f7f5bff492039d8c5e4572.svg)

这里给出运算草稿：

  

![](assets/1608706044-6ec9672d1c3828a22b7c03e8dc4f9843.png)

为什么这里我们会以原点作为第三个点构成三角形呢？其实是跟接下来求多边形面积是有关联的。

### 3\. 求多边形的面积

我们在上面给出的求平面多边形重心的公式中有说到，一般我们会把多边形剖分为多个三角形。  
那么这个剖分点 P 我们可以设在哪里呢？这里先给出结论：这个剖分点可以设置在多边形的内部，也可以设置到外部。

![](assets/1608706044-efe12f2f50c11cd391b6927cf47831d2.png)

为什么这个剖分点可以设置到外部呢？我们可以通过简单的三角形情况来推广到多边形的情况。  
对于三角形ABC，我们把剖分点设置在其外部 P 的一点上

  

![](assets/1608706044-e10fcb15381809b1599cdbd5de6aecb4.png)

如果大家还记得 [《如何判断一个多边形是否合法》](https://links.jianshu.com/go?to=https%3A%2F%2Fjuejin.im%2Fpost%2F5cc7eea351882512fa03a481) 一文中有讲过向量叉积是有正负之分的，并且根据上面所说的计算三角形面积，那么以 P 为剖分点，通过向量积可以得出这个三角形的面积 A 为：  
![A = \frac{1}{2}(\vec{PB} \times \vec{PC} + \vec{PC} \times \vec{PA} + \vec{PA} \times \vec{PB})](assets/1608706044-285b74b38d20b031ed91dbe0c447fb1b.svg)

因为 向量PB 在 向量PA 的顺时针方向，所以 ![\vec{PA} \times \vec{PB}](assets/1608706044-2922eb5825d97e788dae591718bb179f.svg) 的结果是负数的。那么上面的面积计算公式其实就可以理解为：

三角形ABC的面积 = 三角形PBC面积 + 三角形PCA面积 - 三角形PAB面积

假设这四个点的坐标为：![P(x_0,y_0), A(x_1,y_1), B(x_2,y_2), C(x_3,y_3)](assets/1608706044-b90ec9f7551363a7679a4f3d2718737c.svg)，通过上面的公式进行计算，具体的演算过程我就不给出了，这里直接给出计算结果：  
![A = x_1y_2-x_2y_1+x_2y_3-x_3y_2+x_3y_1-x_1y_3](assets/1608706044-59ae90faf701ebea95885b398f72c47a.svg)

我们可以发现，计算结果中没有 ![x_0,y_0](assets/1608706044-bf36ba69ec55233bed63a84850f2e9bb.svg) 的项，因为它们在计算过程中给消去了，数学就是这么奇妙！所以我们可以得出一个结论，多边形的面积结果与这个剖分点的位置是无关的。那么为了计算方便，我们当然选择把这个 P 点设置到原点上啦。

那么只要我们知道多边形的每一个顶点，通过原点进行剖分成多个三角形，然后通过向量的叉乘求出每个三角的面积，最后相加，就可以求出多边形的面积了。

# 示例代码及解析

好了，说到这里，我们已经找到所有满足最开始的计算多边形重心点坐标的所有计算元素了。是时候上代码了，这里构建一个函数`calculatePolygonGravityCenter(coordinates: [CLLocationCoordinate2D])`，这个函数传入的参数是多边形在地图上的坐标点数组。

```swift
func calculatePolygonGravityCenter(coordinates: [CLLocationCoordinate2D]) -> CLLocationCoordinate2D {
    var area = 0.0 // 多边形面积
    var gravityLat = 0.0 // 重心点 latitude
    var gravityLng = 0.0 // 重心点 longitude
    for (index, coordinate) in coordinates.enumerated() {
        // 1
        let lat = coordinate.latitude
        let lng = coordinate.longitude
        let nextLat = coordinates[(index + 1) % coordinates.count].latitude
        let nextLng = coordinates[(index + 1) % coordinates.count].longitude
        // 2
        let tempArea = (nextLat * lng - nextLng * lat) / 2.0
        // 3
        area += tempArea
        // 4
        gravityLat += tempArea * (lat + nextLat) / 3
        gravityLng += tempArea * (lng + nextLng) / 3
    }
    // 5
    gravityLat = gravityLat / area
    gravityLng = gravityLng / area
    
    return CLLocationCoordinate2D(latitude: gravityLat, longitude: gravityLng)
}
```

对应上面代码的注释：

1.  拿到多边形上连续两个点的坐标，我们可以把 latitude 看做横坐标，longitude 是纵坐标。
2.  利用向量叉乘计算这两个点与原点组成的三角形的面积。
3.  所有面积之和得出多边形的面积，就是求公式 ![C_x = \frac{\sum C_{i_x} A_i}{\sum A_i}](assets/1608706044-c35430cd6a04202ff21d763ea469832d.svg) 中的 ![\sum A_i](assets/1608706044-3b8ca23127c7fe7beb194ff9fa3971d0.svg)。
4.  `(lat + nextLat) / 3` 是以这两个点和原点组成的三角形的重心横坐标，这样的累加`gravityLat += tempArea * (lat + nextLat) / 3` 其实是求公式 ![C_x=\frac{\sum C_{i_x} A_i}{\sum A_i}](assets/1608706044-b021bd30a820263e3ad05c76b11e6367.svg) 中的 ![\sum C_{i_x} A_i](assets/1608706044-27740cc0763c3ccf5e1be9b9158298b0.svg) 的值。
5.  到这一步就简单了，直接套用公式 ![C_x=\frac{\sum C_{i_x} A_i}{\sum A_i}](assets/1608706044-b021bd30a820263e3ad05c76b11e6367.svg)。

# 参考资料

1.  [维基百科-Centroid](https://links.jianshu.com/go?to=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FCentroid%23Centroid_of_polygon)
2.  [维基百科-叉积](https://links.jianshu.com/go?to=https%3A%2F%2Fzh.wikipedia.org%2Fwiki%2F%25E5%258F%2589%25E7%25A7%25AF)
3.  [cnblogs-用向量积（叉积）计算三角形的面积和多边形面积](https://links.jianshu.com/go?to=http%3A%2F%2Fwww.cnblogs.com%2Fxiexinxinlove%2Fp%2F3708147.html)
4.  [知乎-两个向量的叉乘为什么是面积](https://links.jianshu.com/go?to=https%3A%2F%2Fwww.zhihu.com%2Fquestion%2F22902370)
5.  [中国知网-任意多边形匀面重心的计算方法](https://links.jianshu.com/go?to=https%3A%2F%2Fkns.cnki.net%2FKCMS%2Fdetail%2Fdetail.aspx%3Fdbcode%3DCFJD%26dbname%3DCJFDLAST2018%26filename%3DSXTB200210014%26v%3DMDk4NThSOGVYMUx1eFlTN0RoMVQzcVRyV00xRnJDVVJMT2ZZK1Z2RmlIblZydk9OalhmYkxHNEh0UE5yNDlFWUk%3D)

5人点赞

[iOS](https://www.jianshu.com/nb/12253092)

"小礼物走一走，来简书关注我"

赞赏支持还没有人赞赏，支持一下

[![  ](assets/1608706044-d18004d6b9757e2ddea5831daf56f836.png)](https://www.jianshu.com/u/200ff3d414b8)

[hanson21](https://www.jianshu.com/u/200ff3d414b8 "hanson21")iOS developer, using Swift. Want to be Full Sta...

总资产2 (约0.15元)共写了8124字获得17个赞共6个粉丝

关注

---------------------------------------------------


原网址: [访问](https://www.jianshu.com/p/39ef232ad531)

创建于: 2020-12-23 14:47:24

目录: default

标签: `www.jianshu.com`

