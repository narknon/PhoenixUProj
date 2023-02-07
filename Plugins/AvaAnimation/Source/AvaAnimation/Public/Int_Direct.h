#pragma once
#include "CoreMinimal.h"
#include "IntProvider.h"
#include "Int_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UInt_Direct : public UIntProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UInt_Direct();
};

