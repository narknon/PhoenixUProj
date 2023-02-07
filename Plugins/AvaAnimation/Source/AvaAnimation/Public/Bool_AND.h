#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Bool_AND.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBool_AND : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBoolProvider*> Children;
    
    UBool_AND();
};

