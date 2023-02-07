#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingMasterStack.generated.h"

class AGlobalLightingMaster;
class UGlobalLightingDefaults;

USTRUCT(BlueprintType)
struct FGlobalLightingMasterStack {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AGlobalLightingMaster> CurrentMaster;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AGlobalLightingMaster>> MasterList;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGlobalLightingDefaults> CinematicOverrideDefaults;
    
    GLOBALLIGHTRIG_API FGlobalLightingMasterStack();
};

