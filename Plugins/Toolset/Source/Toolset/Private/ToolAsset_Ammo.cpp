#include "ToolAsset_Ammo.h"

UToolAsset_Ammo::UToolAsset_Ammo() {
    this->m_clipSize = 1;
    this->m_autoReload = true;
    this->m_reloadDelay = 0.25f;
    this->m_reloadSfx = NULL;
    this->m_reloadAnim = NULL;
    this->m_limitedAmmo = false;
    this->m_startingAmmo = 0;
    this->m_maxAmmo = 0;
    this->m_emptySfx = NULL;
}

