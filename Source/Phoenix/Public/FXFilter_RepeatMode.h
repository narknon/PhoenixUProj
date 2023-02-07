#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "EMultiFXRepeat.h"
#include "FXFilter_RepeatMode.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_RepeatMode : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXRepeat RepeatMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImmediate;
    
public:
    UFXFilter_RepeatMode();
};

