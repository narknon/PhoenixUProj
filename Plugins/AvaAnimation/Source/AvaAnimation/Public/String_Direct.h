#pragma once
#include "CoreMinimal.h"
#include "StringProvider.h"
#include "String_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UString_Direct : public UStringProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Value;
    
    UString_Direct();
};

