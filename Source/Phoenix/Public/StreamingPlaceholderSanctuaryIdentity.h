#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "StreamingPlaceholderChildActorBase.h"
#include "StreamingPlaceholderSanctuaryIdentity.generated.h"

class AActor;

UCLASS(Blueprintable)
class AStreamingPlaceholderSanctuaryIdentity : public AStreamingPlaceholderChildActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, TSoftClassPtr<AActor>> IdentityOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> DefaultActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSwapWhenIdentityChanges;
    
    AStreamingPlaceholderSanctuaryIdentity();
protected:
    UFUNCTION(BlueprintCallable)
    void OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity);
    
};

