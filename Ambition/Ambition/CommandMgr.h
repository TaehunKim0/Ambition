#pragma once

struct Command
{
	int key;
	int CurrentTime;
};

class CommandMgr
{
public:
	CommandMgr();
	~CommandMgr();

	int m_Punch;
	int m_Kick;
	int m_Left;
	int m_Right;

	std::vector<Command> m_Command;

	void SetPunchKick(int key, int key2) {
		m_Punch = key;
		m_Kick = key2;
	}

	void SetLeftRight(int key, int key2) {
		m_Left = key;
		m_Right = key2;
	}

	bool IsPunchCommand()
	{
		auto C = m_Command;

		if(C[0].key == m_Punch && C[1].key == m_Punch && C[2].key == m_Punch)
			if ((C[0].CurrentTime - C[1].CurrentTime) > -30)
			{
				if ((C[1].CurrentTime - C[2].CurrentTime) > -30)
				{
					return true;
				}
			}

		return false;
	}

	bool IsKickCommand()
	{
		auto C = m_Command;

		if (C[0].key == m_Kick && C[1].key == m_Kick && C[2].key == m_Kick)
			if ((C[0].CurrentTime - C[1].CurrentTime) > -30)
			{
				if ((C[1].CurrentTime - C[2].CurrentTime) > -30)
				{
					return true;
				}
			}

		return false;
	}

	bool IsLeftDashCommand()
	{
		auto C = m_Command;

		if (C[0].key == m_Left && C[1].key == m_Left)
		{
			if ((C[0].CurrentTime - C[1].CurrentTime) > -30)
			{
				return true;
			}
		}
		if (m_Command.size() > 2)
			if (C[1].key == m_Left && C[2].key == m_Left)
			{
				if ((C[1].CurrentTime - C[2].CurrentTime) > -30)
				{
					return true;
				}
			}

		return false;
	}


	bool IsRightDashCommand()
	{
		auto C = m_Command;

		if (C[0].key == m_Right && C[1].key == m_Right)
		{
			if ((C[0].CurrentTime - C[1].CurrentTime) > -30)
			{
				return true;
			}

		}
		
		if(m_Command.size() > 2)
			if (C[1].key == m_Right && C[2].key == m_Right)
			{
				if ((C[1].CurrentTime - C[2].CurrentTime) > -30)
				{
					return true;
				}
			}

		return false;
	}

	bool IsBlockCommand()
	{
		auto C = m_Command;

		if (C[0].key == m_Kick && C[1].key == m_Punch)
		{
			if ((C[0].CurrentTime - C[1].CurrentTime) > -30)
			{
				return true;
			}
		}
		else if (C[0].key == m_Punch && C[1].key == m_Kick)
		{
			if ((C[0].CurrentTime - C[1].CurrentTime) > -30)
			{
				return true;
			}
		}


		return false;
	}

	void AddCommand(int key) {
		auto command = Command();
		command.CurrentTime = Time::TotalTime;
		command.key = key;
		m_Command.push_back(command);
	}

};

