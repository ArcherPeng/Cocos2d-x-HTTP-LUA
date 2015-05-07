_G.APUtils = {}
_G.APUtils.Auther = "ArcherPeng"
_G.APUtils.httpSend = _APhttpSendMethod
require("APUtils/EventDispatcher.lua")
require("APUtils/functions.lua")
-- require("framework/display.lua")
----------------弹窗管理------------------
function APUtils.addChildToRuningScene(node,localZOrder)
    local scene = cc.Director:getInstance():getRunningScene()
    if scene then
        local tbChild = scene:getChildren()
        localZOrder = localZOrder or 9999999
        if #tbChild>0 then
            local sceneLayer = tbChild[1]
            sceneLayer:addChild(node,localZOrder) 
        end
    end
end


--字体，gb2312，能加粗
function APUtils.getLabelBold(params)
    local defaultParams = {
        content = "",
        pos = cc.p(0,0),
        anchor = cc.p(0.5,0.5),
        color = cc.c4b(255,255,255,255),
        outcolor = cc.c4b(255,255,255,255),
        fontsize = 24,
        labelwidth = APUtils.width,
        type = 1,--type 1系统字体，2胖娃字体
        outlineSize = 0,--描边粗
        enableShadow = 1,
    }
    if params == nil then params = {} end
    for k, v in pairs(defaultParams) do
        if params[k] == nil then
            params[k] = v
        end
    end

    local labelbold = cc.Label:create()
    if params.type == 1 then
        labelbold:setSystemFontName("Helvetica")
        labelbold:setSystemFontSize(params.fontsize)
        if params.enableShadow == 1 then
            labelbold:enableShadow(cc.c4b(0, 0, 0, 255),cc.size(1,-1),2)
        end

    elseif params.type == 2 then
        local ttfConfig = {}
        ttfConfig.fontFilePath = "res/fonts/pw.ttf"
        ttfConfig.fontSize = params.fontsize
        ttfConfig.outlineSize = params.outlineSize
        labelbold:setTTFConfig(ttfConfig)
    end
    labelbold:setMaxLineWidth(params.labelwidth)
    labelbold:setString(params.content)--猇亭大战
    labelbold:setAlignment(cc.TEXT_ALIGNMENT_LEFT)
    labelbold:setColor(params.color)
    labelbold:setAnchorPoint(params.anchor)
    labelbold:setPosition(params.pos)

    return labelbold
end

