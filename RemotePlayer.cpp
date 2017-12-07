//
// Created by shay on 12/7/17.
//

#include "RemotePlayer.h"
RemotePlayer::RemotePlayer(char playerSign) {
    if (playerSign == 'X') {
        this->sign_ = 'O';
    } else {
        this->sign_ = 'X';
    }
    this->disksNum_ = 2;
}


