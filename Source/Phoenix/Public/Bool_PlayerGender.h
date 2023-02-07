#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "ESexType.h"
#include "Bool_PlayerGender.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UBool_PlayerGender : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESexType PlayerGender;
    
    UBool_PlayerGender();
};

