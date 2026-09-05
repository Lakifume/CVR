# Castlevania Remembrance

<img width="1920" height="420" alt="Banner" src="https://github.com/user-attachments/assets/598fecac-48ba-47c4-ab5a-baed150dec5f" />

CVR is an Unreal Engine fangame combining assets and gameplay elements from all 3 DSVania games to create roguelike runs with high replayability potential.
The core idea and concept of the game is heavily inspired by [Aria of Sorrow Reprise](https://www.inverteddungeon.com/index.php?section=fanworks&page=rando_castlevania_aria_of_sorrow_reprise), a roguelike mod for the GBAvania by Xanthus.

This is a project meant to be in continuous development until its full scope is reached. See the current roadmap projections below.<br/>
Development started in September 2024.

**CVR must remain non-profit and will NOT monetize in any shape or form, as per compliance to the [Konami Copyright Policy](https://eu-support.konami.com/hc/en-gb/articles/9648771731479-Copyrights-Career-Opportunities-Goodies). The game also lacks any original story and thus does not contain any spoilers to official Castlevania titles.**

## Currently in the demo

### Playable characters
- Soma
- Charlotte

### Areas
- Dark Chapel
- 13th Street
- Underground Labyrinth

### Bosses
- Malphas
- Jiang Shi
- Werewolf
- Dracula

### Randomization
- Progression abilities and items
- Equipment and filler items
- Per-room enemy types
- Background music (optional)
- Room gimmicks (optional)

### Difficulties
- Normal

## Roadmap

### Playable characters
- Jonathan
- Sanoa

### Areas
- Garden of madness
- Demon Guest House
- Cursed Clock Tower
- Sandy Grave
- Nation of Fools
- Castle Keep
- Minera Prison Island
- Mystery Manor
- Castle Library

### Bosses
- Dario *
- Brauner **
- Death **
- Mummy Man *
- Gergoth **
- Sisters ***
- Creature *
- Goliath ***
- Barlowe *

### Randomization
- Map layout and connections
- Boss placement

### Difficulties
- Hard

## Never planned
- Dialogues
- Shops
- Unique enemy drops
- Skill mastery
- Sidequests
- Sidemodes

## Controls

### Controller
**Remappable:** 
- Jump
- Primary weapon
- Secondary weapon
- Primary special
- Secondary special
- Movement ability 1
- Movement ability 2
- Accept <-> Cancel

**Non-remappable:** 
- **Pause menu:** Start
- **Map viewer:** Select
- **Map Marker:** Top face button
- **Tab Left:** Left shoulder
- **Tab Right:** Right shoulder
- **Page Up:** Left Trigger
- **Page Down:** Right Trigger
- **Zoom In:** Right Trigger
- **Zoom Out:** Left Trigger

### Keyboard
**Non-remappable:** 
- **Jump:** Z
- **Primary weapon:** X
- **Secondary weapon:** C
- **Primary special:** A
- **Secondary special:** S
- **Movement ability 1:** Left Shift
- **Movement ability 2:** D
- **Accept:** Z
- **Cancel:** X
- **Pause menu:** Enter
- **Map viewer:** Spacebar
- **Map Marker:** S
- **Tab Left:** Q
- **Tab Right:** E
- **Page Up:** A
- **Page Down:** D
- **Zoom In:** D
- **Zoom Out:** A

### Mouse
**Non-remappable:** 
- **Accept:** Left click
- **Cancel:** Right click
- **Scroll:** Mouse wheel

## Tips and tricks
Currently the game contains no tutorials, here are some useful things to know:
- On Windows the game can only respond to controllers that are connected or converted to Xinput
- Confirm and Back mappings will be automatically swapped based on the Controller Style chosen in the settings menu
- If not using the mouse to navigate menus make sure to leave the cursor on the edge of the screen so that it does not conflict with controller focus
- While magical abilities have dedicated buttons pressing attack while holding UP also triggers them
- Almost every weapon has a super technique that can be activated with the Hadoken input command which provides brief invulnerability
- By default landing will cancel any attack animation instantly, however you can force an animation to bypass this by holding DOWN as you land
- Parts of a room are sometimes hidden behind fake tile layers. These hidden zones always have at least a subtle indicator that they exist
- The digits next to your health bar act as a countdown that tracks how many item checks are left to be discovered in your current area
- On rare occasions an enemy will spawn golden, tremendously increasing its rewards but making it much harder to kill
- The restart to first room feature in the pause menu is only available if you have no statuses at full health while grounded with no enemies in sight
- The demo does not have any proper ending screen yet, beating a run will automatically fade back to the title screen

## Known bugs
- Holding down a direction on the keyboard or dpad while exiting the menu will continuously rapid fire that input until released

## Credits

### Game Design
- Lakifume

### IP and Assets
- Konami

### Game Engine
- Epic Games

### Special Thanks
- Unreal Source Discord
- Castlevania Fighter
- Morell Sunweaver
- chrisaegrimm

## AI disclosure
Generative AI has only been used to draw the letters of the game's logo subtitle to match that of the official font style.<br/>
I am hoping to eventually replace those by that of a real artist's down the line.

## Discord
This project does have a dedicated Discord server, however the permanent link can only be accessed from the game's title screen to mitigate bot spam.

## Running from source

### Prerequisites
- [Unreal Engine 5.4.4](https://dev.epicgames.com/documentation/unreal-engine/install-unreal-engine)
- [Visual Studio 17.8](https://dev.epicgames.com/documentation/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine)
- [Cross-Compile Toolchain v22](https://dev.epicgames.com/documentation/unreal-engine/linux-development-requirements-for-unreal-engine) (if packaging for Linux from Windows)

### Plugins (included in project source)
- PaperZD
- Low Entry Extended Library
- Sprite Tools (optional)

### Editor setup
In the Unreal Editor go to Edit > Editor Preferences and set the following:
- Level Editor > Viewports > Look and Feel > Advanced > Billboard Scale -> 0.5
- Level Editor > Viewports > Grid Snapping > Use Power of Two Snap Size -> true
