<%--
  Created by IntelliJ IDEA.
  User: 魏志杰
  Date: 2022/9/20
  Time: 18:08
  To change this template use File | Settings | File Templates.
--%>
    <%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
    <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
    <html>
<body>
<script type="text/javascript">
    function fun(){
        var sum=0;var max=0;var min=1000000000;
        var x=document.getElementsByName("b");
        var tmp=0.0;
        for(var i=0;i<x.length;i++){
            if(x[i].value==""){
                tmp=0.0;
                alert("请输入全部10本书的价格!");
                sum=0.0;
                min=0.0;
                max=0.0;
                break;
            }
            else{
                tmp=parseFloat(x[i].value);
            }
            sum=sum+tmp;
            if(max<tmp){max=tmp;}
            if(min>tmp){min=tmp;}
        }

        document.getElementById("max").value=max;
        document.getElementById("min").value=min;
        document.getElementById("sum").value=sum;
        return;
    }
</script>
<p>请输入10本书的价格</p>
<form name="bookprice">
    <%
        for(int i=1;i<=10;i++){
    %>book<%= i%><input name="b" type="text"><BR><%
    }
%>
    <input type="button" onclick="fun()" value="提交"><BR>
    最高价格<input id="max" type="text"  readonly><BR>
    最低价格<input id="min" type="text"  readonly><BR>
    价格总和<input id="sum" type="text"  readonly><BR>
</form>
</body>
</html>


