
cc.FileUtils:getInstance():addSearchPath("src")
cc.FileUtils:getInstance():addSearchPath("res")

-- CC_USE_DEPRECATED_API = true
require "cocos.init"


-- cclog
cclog = function(...)
    print(string.format(...))
end


--初始化基础库
require("APUtils/common.lua")
_G.APUtils.Version = "0.0.1"

local currentPlant =  cc.Application:getInstance():getTargetPlatform()

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    -- initialize director
    local director = cc.Director:getInstance()
    local glview = director:getOpenGLView()
    if nil == glview then
        glview = cc.GLViewImpl:createWithRect("HelloLua", cc.rect(0,0,900,640))
        director:setOpenGLView(glview)
    end

    -- glview:setDesignResolutionSize(480, 320, cc.ResolutionPolicy.NO_BORDER)
    if currentPlant == cc.PLATFORM_OS_IPAD then
        glview:setDesignResolutionSize(768, 1024, cc.ResolutionPolicy.FIXED_HEIGHT)
    else
        glview:setDesignResolutionSize(640, 1138, cc.ResolutionPolicy.FIXED_WIDTH)
    end

    --turn on display FPS
    director:setDisplayStats(true)

    --set FPS. the default value is 1.0/60 if you don't call this
    director:setAnimationInterval(1.0 / 60)

    local schedulerID = 0
    --support debug
    local targetPlatform = cc.Application:getInstance():getTargetPlatform()
    if (cc.PLATFORM_OS_IPHONE == targetPlatform) or (cc.PLATFORM_OS_IPAD == targetPlatform) or
       (cc.PLATFORM_OS_ANDROID == targetPlatform) or (cc.PLATFORM_OS_WINDOWS == targetPlatform) or
       (cc.PLATFORM_OS_MAC == targetPlatform) then
        cclog("result is ")
        --require('debugger')()

    end
   
    cclog(_G.APUtils.Auther)
    ---------------
    


    -- run
    local scene = require("GameScene")
    local gameScene = scene.create()
    if cc.Director:getInstance():getRunningScene() then
        cc.Director:getInstance():replaceScene(gameScene)
    else
        cc.Director:getInstance():runWithScene(gameScene)
    end
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    --提示错误的日志
    local tbChild = cc.Director:getInstance():getRunningScene():getChildren()
    if #tbChild>0 then
        local sceneLayer = tbChild[1]
        local sp = cc.LayerColor:create(cc.c4b(102,102,102,255),sceneLayer:getContentSize().width/4*3,sceneLayer:getContentSize().height/4*3)
        sp:setPosition(sceneLayer:getContentSize().width/2-sp:getContentSize().width/2,sceneLayer:getContentSize().height/2-sp:getContentSize().height/2)

        sceneLayer:addChild(sp,999999) 
        
        local label = cc.Label:createWithSystemFont("LUA ERROR: " .. tostring(msg),"Arial",25,cc.size(sp:getContentSize().width-65,sp:getContentSize().height-65),0,1)
        
        label:setPosition(sp:getContentSize().width/2,sp:getContentSize().height/2)
        sp:addChild(label)
    end
    --显示栈上的局部变量
    cclog(debug.traceback())
    cclog("----------------------------------------")
    return msg
end
local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    error(msg)
end
