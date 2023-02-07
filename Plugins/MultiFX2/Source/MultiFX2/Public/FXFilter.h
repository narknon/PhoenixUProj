#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXFilter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class MULTIFX2_API UFXFilter : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNot;
    
    UFXFilter();
};

