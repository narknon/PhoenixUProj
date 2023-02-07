#pragma once
#include "CoreMinimal.h"
#include "FXEnd.h"
#include "MultiFX2End_Sfx.generated.h"

class UAkAudioEvent;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2End_Sfx : public UFXEnd {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayOnExistingAkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayAtLocation;
    
public:
    UMultiFX2End_Sfx();
};

