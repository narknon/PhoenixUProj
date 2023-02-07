#pragma once
#include "CoreMinimal.h"
#include "EUIScreenType.generated.h"

UENUM(BlueprintType)
enum class EUIScreenType : uint8 {
    UIST_Screen,
    UIST_NonModalTutorial,
    UIST_ModalTutorial,
    UIST_Popup,
    UIST_MAX UMETA(Hidden),
};

