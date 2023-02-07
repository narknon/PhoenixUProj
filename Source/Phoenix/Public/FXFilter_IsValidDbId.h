#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsValidDbId.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsValidDbId : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ValidDbIds;
    
public:
    UFXFilter_IsValidDbId();
};

