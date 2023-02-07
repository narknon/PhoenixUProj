#pragma once
#include "CoreMinimal.h"
#include "FXEnd.h"
#include "MultiFX2Handle.h"
#include "MultiFX2End_Fadeout.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2End_Fadeout : public UFXEnd {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutTime;
    
public:
    UMultiFX2End_Fadeout();
protected:
    UFUNCTION(BlueprintCallable)
    void EndFade(FMultiFX2Handle InHandle, const UMultiFX2_Base* FXBase);
    
};

