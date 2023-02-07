#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "EObjectSizeClass.h"
#include "FXFilter_IsValidSize.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsValidSize : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectSizeClass SmallestValidSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectSizeClass LargestValidSize;
    
public:
    UFXFilter_IsValidSize();
};

