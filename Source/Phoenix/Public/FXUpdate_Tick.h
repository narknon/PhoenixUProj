#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "MultiFX2Handle.h"
#include "FXUpdateInfo.h"
#include "FXUpdate_Tick.generated.h"

class UMultiFX2_Base;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_Tick : public UFXUpdate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FMultiFX2Handle, FFXUpdateInfo> UpdateInfos;
    
public:
    UFXUpdate_Tick();
    UFUNCTION(BlueprintCallable)
    void Update(FMultiFX2Handle InHandle, const UMultiFX2_Base* InMultiBase);
    
};

