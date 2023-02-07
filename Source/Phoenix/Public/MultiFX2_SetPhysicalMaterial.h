#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_SetPhysicalMaterial.generated.h"

class UPhysicalMaterial;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_SetPhysicalMaterial : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicalMaterial* PhysicalMaterial;
    
public:
    UMultiFX2_SetPhysicalMaterial();
};

