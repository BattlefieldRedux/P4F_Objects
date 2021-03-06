
rem *** Animations ***
animationSystem.createAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_sit.baf
animationManager.looping 0
animationSystem.createAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_stand.baf
animationManager.looping 0
animationSystem.createAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_duck.baf
animationManager.looping 0
animationSystem.createAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_die.baf
animationManager.looping 0

rem *** Bundles ***
animationSystem.createBundle lookAround
animationBundle.isLooping 0
animationBundle.playBackward 1
animationBundle.fadeInTime 0
animationBundle.fadeOutTime 0
animationBundle.useSpeedAsTime 1
animationBundle.addAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_stand.baf
animationBundle.addAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_sit.baf

animationSystem.createBundle lookAroundDuck
animationBundle.isLooping 1
animationBundle.playBackward 1
animationBundle.fadeInTime 0.2
animationBundle.fadeOutTime 0.2
animationBundle.useSpeedAsTime 1
animationBundle.addAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_duck.baf

animationSystem.createBundle lookAroundDie
animationBundle.isLooping 0
animationBundle.playBackward 1
animationBundle.fadeInTime 0.4
animationBundle.fadeOutTime 0
animationBundle.useSpeedAsTime 1
animationBundle.addAnimation Objects/Vehicles/Land/JEP_Vodnik/Animations/3p/3p_vodnik_gunner_die.baf

rem *** Triggers ***
animationSystem.createTrigger LookAroundTrigger stand
animationTrigger.addBundle lookAround
animationTrigger.valueHolder 3p_turnRight

animationSystem.createTrigger LookAroundTrigger duck
animationTrigger.addBundle lookAroundDuck
animationTrigger.valueHolder 3p_turnRight

animationSystem.createTrigger LookAroundTrigger die
animationTrigger.addBundle lookAroundDie
animationTrigger.valueHolder 3p_turnRight

animationSystem.createTrigger PoseTrigger root
animationTrigger.addChild stand
animationTrigger.addChild duck

animationSystem.createTrigger Trigger completeTree
animationTrigger.addChild root
animationTrigger.addChild die



