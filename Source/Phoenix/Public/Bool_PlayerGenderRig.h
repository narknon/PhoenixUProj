#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "EGenderEnum.h"
#include "Bool_PlayerGenderRig.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UBool_PlayerGenderRig : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGenderEnum Rig;
    
    UBool_PlayerGenderRig();
};

