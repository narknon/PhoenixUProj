#pragma once
#include "CoreMinimal.h"
#include "NameProvider.h"
#include "Name_Conditional.generated.h"

class UBoolProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_Conditional : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* Value;
    
    UName_Conditional();
};

