#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "MultiFX2Handle.h"
#include "FXUpdate_Timed.generated.h"

class UMultiFX2_Base;
class UWorld;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_Timed : public UFXUpdate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
public:
    UFXUpdate_Timed();
protected:
    UFUNCTION(BlueprintCallable)
    void DeactivateFX(FMultiFX2Handle InHandle, const UMultiFX2_Base* FXBase);
    
};

