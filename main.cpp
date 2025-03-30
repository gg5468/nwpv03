#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class main_dialog : public vsite::nwp::dialog 
{
public:
	POINT point;
protected:
	int idd() const override
	{ 
		return IDD_DIALOG1; 
	}
	bool on_init_dialog() override


	{
		this->set_int(IDC_EDIT1, point.x);
		this->set_int(IDC_EDIT2, point.y);
		return true;
	}
	bool on_ok() override
	{
		point.x = this->get_int(IDC_EDIT1);
		point.y = this->get_int(IDC_EDIT2);
		return true;
	}
	void on_cancel() override { }
	bool on_command(int id, int code) override { return false; }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	main_dialog dlg;
	GetCursorPos(&dlg.point);
	if(dlg.do_modal(instance, 0) == IDOK)
	{
		SetCursorPos(dlg.point.x, dlg.point.y);
	}
	return 0;
}
