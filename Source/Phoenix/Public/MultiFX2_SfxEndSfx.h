#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Sfx.h"
#include "MultiFX2_SfxEndSfx.generated.h"

class UAkAudioEvent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_SfxEndSfx : public UMultiFX2_Sfx {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EndSfx;
    
public:
    UMultiFX2_SfxEndSfx();
};

