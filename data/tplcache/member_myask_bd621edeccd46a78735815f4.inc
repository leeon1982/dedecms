<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang;?>" />
<title>我的提问</title>
<link href="<?php echo $cfg_ask_basehost;?>/member/templets/style/base.css" rel="stylesheet" type="text/css" />
<script language="javascript" type="text/javascript" src="<?php echo $cfg_ask_basehost;?>/images/js/j.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $cfg_ask_basehost;?>/member/js/table_function.js"></script>
</head>
<body>
<div id="main">
  <?php include(DEDEASK."/templates/default/head.htm"); ?>
  <div id="content" class="w960 clearfix">
    <?php include(DEDEASK."/templates/default/menu.php");?>
    <div id="mcpmain">
      <div id="appTab">
        <ul>
          <li class="thisTab"><a href="#">我的提问</a></li>
          <li><a href="?ct=myask&ac=answer">我的回答</a></li>
        </ul>
        <div class="tabOther">
        <?php 
        	if($cfg_ask_isdomain == 'Y') $askrul = $cfg_ask_domain.'/?ct=question&ac=ask';
            else $askrul = $cfg_ask_directory.'/?ct=question&ac=ask';
        ?>
          <span class="fRight mR10 titPublish icon"><a href='<?php echo $askrul;?>' target="_blank">+发出提问</a></span>
        </div>
      </div>
      <div id="mainCp">
        <h3 class="meTitle">我的提问</h3>
        <div class="postForm">
           <table  width="100%" border="0" cellpadding="0" cellspacing="0" class="list">
            <thead>
              <tr>
                <th>标题</th>
                <th width="10%">悬赏积分</th>
                <th width="10%">回答数</th>
                <th width="10%">状态</th>
                <th width="18%">提问时间</th>
                <th width="18%">回复时间</th>
              </tr>
            </thead>
            <tbody>
            
            <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{

				$fields['dateline'] = GetDateMk($fields['dateline']);
				if($fields['status'] == 1){
					$fields['dbstatus'] = 1;
					$fields['status'] = '<font color="green">已解决</font>';
				}elseif($fields['expiredtime'] < $timestamp) {
					$fields['dbstatus'] = 3;
					$fields['status'] = '<i>已过期</i>';
				}elseif($fields['status'] == 2) {
					$fields['dbstatus'] = 2;
					$fields['status'] = '<font color="#999">已结束</font>';
				}else{
					$fields['dbstatus'] = 0;
					$fields['status'] = '<font color="red">未解决</font>';
				}
                //对连接地址进行处理
                if($cfg_ask_isdomain == 'Y')
                {
                	if($cfg_ask_rewrite == 'Y')
                		$qurl = $cfg_ask_domain.'/'.$fields['id'].'html';
                    else
                        $qurl = $cfg_ask_domain.'?ct=question&askaid='.$fields['id'];
                }else{
                    if($cfg_ask_rewrite == 'Y')
                		$qurl = $cfg_ask_directory.'/'.$fields['id'].'html';
                    else
                        $qurl = $cfg_ask_directory.'/?ct=question&askaid='.$fields['id'];
                }
		  ?>
            <tr>
              <td><a href="<?php echo $qurl;?>" target='_blank'><?php echo $fields['title'];?></a></td>
              <td align="center"><?php echo $fields['reward'] ;?></td>
              <td align="center"><?php echo $fields['replies'];?></td>
              <td align="center"><?php echo $fields['status'] ;?></td>
              <td align="center"><?php echo $fields['dateline'] ;?></td>
              <td align="center"><?php 
              if(!empty($fields['lastanswer'])) echo MyDate('Y-m-d h:m:s', $fields['lastanswer']);
              else echo '尚未回复';?></td>
            </tr>
            <?php
}
}?>
            </tbody>
            
            <tfoot>
              <tr>
                <td colspan="7"><div class="pages mTB10 fRight"><?php
$atts = array();
$atts['tagname'] = 'pagelist';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
</div>
                  <div class="clear"></div></td>
              </tr>
            </tfoot>
          </table>    
       </div>

      <!--主操作区域 -->
    </div>
  </div>
</div>
<?php include(DEDEMEMBER."/templets/foot.htm"); ?>
</div>

</body>
</html>