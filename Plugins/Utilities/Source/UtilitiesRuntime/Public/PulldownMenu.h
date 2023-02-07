#pragma once
#include "CoreMinimal.h"
#include "Components/ComboBoxString.h"
#include "PulldownMenu.generated.h"

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UPulldownMenu : public UComboBoxString {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LockPulldownWidth;
    
    UPulldownMenu();
};

