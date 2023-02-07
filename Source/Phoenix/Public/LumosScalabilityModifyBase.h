#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LumosScalabilityModifyBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ULumosScalabilityModifyBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bContinueModifiers;
    
    ULumosScalabilityModifyBase();
};

