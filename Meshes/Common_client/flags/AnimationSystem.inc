
rem *** Animations ***
animationSystem.createAnimation Objects/Common/Flags/Animation/flag_idle.baf
animationManager.length 18

rem *** Bundles ***
animationSystem.createBundle flag_idle
animationBundle.fadeInTime 0.1
animationBundle.fadeOutTime 0.2
animationBundle.addAnimation Objects/Common/Flags/Animation/flag_idle.baf


rem *** Triggers ***
animationSystem.createTrigger Trigger root
animationTrigger.addBundle flag_idle

