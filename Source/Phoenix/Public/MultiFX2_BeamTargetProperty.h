#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_BeamTargetBase.h"
#include "MultiFX2_BeamTargetProperty.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_BeamTargetProperty : public UMultiFX2_BeamTargetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PropertyName;
    
    UMultiFX2_BeamTargetProperty();
};

