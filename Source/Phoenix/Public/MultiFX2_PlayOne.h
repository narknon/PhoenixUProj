#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_PlayOne.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_PlayOne : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> PlayOneFXBaseArray;
    
public:
    UMultiFX2_PlayOne();
};

