#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\not11.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\nand22.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\nor22.jpg";
	MenuItemImages[ITM_BUF] = "images\\Menu\\buffer11.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\xor22.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\xnor22.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\nor33.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor33.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\switch1.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Led1.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\connection1.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\play1.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	MenuItemImages[ITM_COPY] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\paste.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\edit.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\redo.jpg";
	MenuItemImages[ITM_PLAY] = "images\\Menu\\play.jpg";
	MenuItemImages[ITM_PAUSE] = "images\\Menu\\pause.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\load.jpg";
	

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{

	UI.AppMode = SIMULATION;	//Simulation Mode

	string MenuItemImages[ITM_SIM_CNT];
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	MenuItemImages[ITM_SIM] = "images\\Menu\\exit.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\truth_table.jpg";

	/*MenuItemImages[ITM_EDIT] = "images\\Menu\\edit.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\paste.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\redo.jpg";
	MenuItemImages[ITM_PLAY] = "images\\Menu\\play.jpg";
	MenuItemImages[ITM_PAUSE] = "images\\Menu\\pause.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\load.jpg";
	*/
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.SIMToolItemWidth, 0, UI.SIMToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}
void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_not11_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_not11.jpg";

	//Draw INV Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by INV Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.INV_Width, UI.INV_Height);
}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_nand22_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_nand22.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_nor22_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_nor22.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}
void Output::DrawBUF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_buffer11_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_buffer11.jpg";

	//Draw BUF Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by BUF Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUF_Width, UI.BUF_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_xor22_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_xor22.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_xnor22_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_xnor22.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_and3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_and3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_nor33_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_nor33.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_xor33_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_xor33.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected,bool sim) const
{
	string GateImage;
	if (selected && sim == true)
		GateImage = "Images\\Gates\\Gate_switch_Hi.jpg";
	else if (selected && sim==false)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_switch_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_switch.jpg";

	//Draw Switch Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by switch Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected,bool sim) const
{
	string GateImage;
	if ( sim == true)
		GateImage = "Images\\Gates\\Gate_LED_Hi.jpg";
	else if (selected && sim == false)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_LED_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_LED.jpg";

	//Draw LED Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	color c;
	c = (selected ? RED : BLACK);
	pWind->SetPen(c, 3);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x1 + r_GfxInfo.x2) / 2, r_GfxInfo.y1);
	pWind->DrawLine((r_GfxInfo.x1 + r_GfxInfo.x2) / 2, r_GfxInfo.y1, (r_GfxInfo.x1 + r_GfxInfo.x2) / 2, r_GfxInfo.y2);
	pWind->DrawLine((r_GfxInfo.x1 + r_GfxInfo.x2) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

	//TODO: Add code to draw connection
}



/* Draws the hovered label */
void Output::DrawLabel(int x, int y, const string& label) const
{
	int w, h;
	pWind->SetBrush(BLACK);
	pWind->SetPen(BLACK);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->GetStringSize(w, h, label);
	pWind->DrawString(x - 50, y - 50, label);
}


Output::~Output()
{
	delete pWind;
}