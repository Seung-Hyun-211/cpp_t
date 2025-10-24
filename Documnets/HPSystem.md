# 체력 시스템

## 체력 시스템 설명

체력 회복 : 일정량의 체력을 순간 회복<br>
체력 재생 : 초당 일정량의 체력을 지속적으로 회복<br>
임시 체력<br>
- isImmediateDamage가 false일 경우 데미지만큼 현재 체력이 감소할 경우 해당 데미지 만큼 임시체력을 얻습니다.
- 초당 tempHpChangePerSec 만큼 감소<br>



## 변수 설명

|변수명|설명|
|-|-|
|maxHp|최대 체력|
|currentHp|현재 체력|
|recoverable|회복 한계치|
|hpChangePerSec|초당 체력 변화량|

|isImmediateDamage|체력을 즉시 잃는지 여부|
|isDead|생사 여부|

