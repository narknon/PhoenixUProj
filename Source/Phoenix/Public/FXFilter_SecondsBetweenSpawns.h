#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_SecondsBetweenSpawns.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_SecondsBetweenSpawns : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondsBetweenSpawns;
    
public:
    UFXFilter_SecondsBetweenSpawns();
};

