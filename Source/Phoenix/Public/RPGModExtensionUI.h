#pragma once
#include "CoreMinimal.h"
#include "ModExtension.h"
#include "RPGUIInfo.h"
#include "RPGModExtensionUI.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGModExtensionUI : public UModExtension {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSendUINotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGUIInfo UIInfo;
    
    URPGModExtensionUI();
};

