/*
    Copyright 2019-2020 Hydr8gon

    This file is part of NooDS.

    NooDS is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NooDS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with NooDS. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef NOO_FRAME_H
#define NOO_FRAME_H

#include <thread>
#include <wx/wx.h>
#include <wx/joystick.h>

#include "../core.h"

struct Emulator
{
    Core *core = nullptr;
    bool running = false;
    bool frameReset = false;
};

class NooFrame: public wxFrame
{
    public:
        NooFrame(wxJoystick *joystick, Emulator *emulator, std::string path);

        void pressKey(int key);
        void releaseKey(int key);

    private:
        wxJoystick *joystick;
        Emulator *emulator;

        wxMenu *systemMenu;

        std::string ndsPath, gbaPath;
        std::thread *coreThread = nullptr;
        std::vector<int> axisBases;
        int fpsLimiterBackup = 0;
        bool fullScreen = false;

        void runCore();
        void startCore();
        void stopCore();

        void loadRom(wxCommandEvent &event);
        void bootFirmware(wxCommandEvent &event);
        void pause(wxCommandEvent &event);
        void restart(wxCommandEvent &event);
        void stop(wxCommandEvent &event);
        void pathSettings(wxCommandEvent &event);
        void inputSettings(wxCommandEvent &event);
        void layoutSettings(wxCommandEvent &event);
        void directBootToggle(wxCommandEvent &event);
        void fpsDisabled(wxCommandEvent &event);
        void fpsLight(wxCommandEvent &event);
        void fpsAccurate(wxCommandEvent &event);
        void threaded2D(wxCommandEvent &event);
        void threaded3D0(wxCommandEvent &event);
        void threaded3D1(wxCommandEvent &event);
        void threaded3D2(wxCommandEvent &event);
        void threaded3D3(wxCommandEvent &event);
        void exit(wxCommandEvent &event);
        void joystickInput(wxJoystickEvent &event);
        void close(wxCloseEvent &event);

        wxDECLARE_EVENT_TABLE();
};

#endif // NOO_FRAME_H
