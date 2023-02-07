#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Bool_NOT.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBool_NOT : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* Child;
    
    UBool_NOT();
};

