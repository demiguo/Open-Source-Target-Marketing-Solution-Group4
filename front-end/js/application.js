//===================================================================//
//                         UI command hooks                          //
//===================================================================//

function action_Index() {
    // 点击功能栏切换中心区域
    $('#div_page1').hide();
	$('#div_page2').hide();
    $('#div_page3').hide();
	$('#div_page4').hide();
	
    $("#content").show();
}

function action_Page1() {
    $('#div_page1').show();
	$('#div_page2').hide();
    $('#div_page3').hide();
	$('#div_page4').hide();
	
    $("#content").hide();
}

function action_Page2() {
    $('#div_page1').hide();
	$('#div_page2').show();
    $('#div_page3').hide();
	$('#div_page4').hide();
	
    $("#content").hide();
}

function action_Page3() {
    $('#div_page1').hide();
	$('#div_page2').hide();
    $('#div_page3').show();
	$('#div_page4').hide();
	
    $("#content").hide();
}

function action_Page4() {
    $('#div_page1').hide();
	$('#div_page2').hide();
    $('#div_page3').hide();
	$('#div_page4').show();
	
    $("#content").hide();
}



//===================================================================//
//                           Main function                           //
//===================================================================//

$( document ).ready(function() {
    // 中间区域div的默认显隐 
	$('#div_page1').hide();
	$('#div_page2').hide();
    $('#div_page3').hide();
	$('#div_page4').hide();
	
    $("#content").show();
	
    // 左侧菜单的点击事件
    $("#action_Index").click(action_Index);
    $("#action_Page1").click(action_Page1);
	$("#action_Page2").click(action_Page2);
	$("#action_Page3").click(action_Page3);
	$("#action_Page4").click(action_Page4);
    
	// 左侧菜单的active样式切换
	$('ul.nav > li').click(function (e) {
		e.preventDefault();
		$('ul.nav > li').removeClass('active');
		$(this).addClass('active');

	});

});



