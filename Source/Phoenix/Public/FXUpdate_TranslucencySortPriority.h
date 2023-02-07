#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "FXUpdate_TranslucencySortPriority.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_TranslucencySortPriority : public UFXUpdate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TranslucencySortPriority;
    
public:
    UFXUpdate_TranslucencySortPriority();
};

