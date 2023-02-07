#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterfaceAkEventInfo.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FNiagaraDataInterfaceAkEventInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AkAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPointName;
    
    NIAGARAHELPERS_API FNiagaraDataInterfaceAkEventInfo();
};

