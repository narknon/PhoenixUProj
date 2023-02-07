#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsPlayer : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TreatPlayerMountAsPlayer;
    
public:
    UFXFilter_IsPlayer();
};

