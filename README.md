# Breakout

W Kavanagh. June Summer 2024

## controls

A/D to move the paddle right and left.
P to pause.

## Powerups

big/small paddle (blue)
fast/slow ball (fancy yellow)
fire ball (green)

# Tasklist

## Suggested fixes

* Fix the compiler issues in the code


## Suggested tasks

* Implement mouse input for pad
* Improved VFX (ball trail, paddle hit response, brick particle destruction)
* Better UI (progress bar rather than timer for countdown).
* GameLoop
* Better ball physics (Box2D)
* Leaderboards
* More ball types (e.g., multiball, sticky ball [where you shoot the ball from the paddle every time], tiny ball, big ball, brick-tracking ball)
* Sounds with increasing tone between bounces.
* Implement commentary with calls to an LLM such as LLama

# Time Details and Changelist
<Add information to this section about the time you've taken for this task along with a professional changelist.>

*[30 Seconds] Bug Fix:		Removing Circular Dependency
*[20 Minutes] Mouse Movement: 	Paddle Moves directly to Mouse Position without Movement Speed
*[60 Minutes] Ball Trail VFX:	Sprites are spawned at regular at the balls position which decrease in size and then despawn
*[30 Minutes] Powerup Bar: 	Two sprites make up a bar that decreases as a powerup timer decreases
*[30 Minutes] Brick Movement: 	Bricks are moved from left to right based on a timer handled in the Brick Manager
*[20 Minutes] Ball Velocity: 	Ball Velocity Increases On Collision With the Paddle and Resets to Default when a Life is Lost
*[20 Minutes] Paddle Collision:	Paddle switches to red and lerps back to the default cyan colour over time
*[10 Minutes] Paddle Collision:	Paddle height scales to half and morphs back to full over time