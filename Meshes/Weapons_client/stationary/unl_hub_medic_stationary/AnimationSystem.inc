
rem *** Animations ***
animationSystem.createAnimation Objects/Weapons/stationary/unl_hub_medic_stationary/animations/unl_hub_medic_stationary_idle.baf
animationSystem.createAnimation Objects/Weapons/stationary/unl_hub_medic_stationary/animations/unl_hub_medic_stationary_open.baf
animationManager.looping 0

rem *** Bundles ***
animationSystem.createBundle open
animationBundle.isLooping 0
animationBundle.fadeInTime 0
animationBundle.fadeOutTime 0
animationBundle.playForever 1
animationBundle.stickAround 0.1
animationBundle.addAnimation Objects/Weapons/stationary/unl_hub_medic_stationary/animations/unl_hub_medic_stationary_open.baf

animationSystem.createBundle idle
animationBundle.fadeOutTime 0
animationBundle.addAnimation Objects/Weapons/stationary/unl_hub_medic_stationary/animations/unl_hub_medic_stationary_idle.baf

rem *** Triggers ***
animationSystem.createTrigger Trigger open
animationTrigger.addBundle open

animationSystem.createTrigger Trigger stand
animationTrigger.addBundle idle

animationSystem.createTrigger CountTrigger idle
animationTrigger.addChild open
animationTrigger.addChild stand

animationSystem.createTrigger Trigger root
animationTrigger.addChild idle

animationSystem.createTrigger Trigger completeTree
animationTrigger.addChild root

