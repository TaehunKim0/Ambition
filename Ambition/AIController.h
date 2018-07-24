#pragma once
class AIController : public Controller
{
public:
	AIController();
	~AIController();

	bool IsLeftMove() { return false; };
	bool IsRightMove() { return false; };
	bool IsJump() { return false; };
	bool IsPunch() { return false; };
	bool IsKick() { return false; };
	bool IsJumpPunch() { return false; };
	bool IsJumpKick() { return false; };
};

