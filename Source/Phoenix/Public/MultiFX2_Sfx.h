#pragma once
#include "CoreMinimal.h"
#include "EAkCallbackType.h"


#include "MultiFX2_Filtered.h"
#include "ESfxOcclusion.h"
#include "MultiFX2_Sfx.generated.h"

class UAkAudioEvent;
class UAkCallbackInfo;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_Sfx : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* SFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayAtLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDeactivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopWhenTargetDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExistingAKComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNoOcclusionOnPlayerTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNoOcclusionOnPlayerInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESfxOcclusion Occlusion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMotionListener;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePlayerOrientatedMotionListener;
    
public:
    UMultiFX2_Sfx();
protected:
    UFUNCTION(BlueprintCallable)
    void OnAkPostEventFunc(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo) const;
    
};

