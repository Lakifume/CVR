## 0.5.1

### Additions
- Implemented keyboard input remapping
- Added full remapping to confirm and back for gamepad
- Added toggle for allowing up attack inputs on spells
- Added area name and item completion display on the warping window
- Added a post-win result screen with final grading
- Added new room gimmick: "Retro Display"
- Added new headgear: "Thorn Crown"
- Added new accessory: "Fool's Tablet"
- Revamped game logo thanks to lvlvkun
### Adjustments
- Changed controller style toggle to a purely cosmetic input display option
- Renamed reload and restart actions in the pause menu to eliminate confusion
- Set the default gamepad input for secondary attack to bottom face button
- Adjusted joystick deadzone sensitivity
- Increased map marker limit
- Set the first camera pan sequence to be faster if the intro was skipped
- Adjusted collision in DAC_019 to prevent cheesing the bottom chest
- Adjusted knockback direction rules to mitigate lava boosting
- Added platforms to all downward entrances in 13th Street
- Adjusted tiling in residential 13th Street
- Set slide bounces to ignore breakable candles
- Made breakable candle hurtboxes more generous
- Adjusted the hitbox of a variety of player weapons
- Increased Book of Water super damage
- Set Charlotte's spell charging speed to scale with the SPD stat
- Reduced the spell charging speed increase from the Sorceress Crest
- Excluded unaffordable spells from the starting pool
- Set familiars search radius to originate from the player rather than themselves
- Set room gimmicks to end on boss defeat flash
- Set background wolf summons to despawn upon defeating Great Lycan
- Set gold enemy kills to count for 5 instead of 1
- Increased enemy kill ceiling for stat boosts
- Increased Bone Pillar fire downtime variation
- Reduced Lerajie downtime after landing from a jump
- Delayed the Jack O Bones despawn time
### Bugfixes
- Fixed a slight collision mismatch in MET_015
- Fixed Treasure Hat display not showing when reloading the game
- Fixed missing stone circle rocks when cast at the edge of the room
- Detached Student Witch's dust effects from the broom
### Optimization
- Optimized performance of candle-lit rooms in Underground Labyrinth
- Optimized lighting of the title screen scene
- Improved UI scalability across aspect ratios

## 0.5.0
- Initial Win64 and Linux release
