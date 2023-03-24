#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ELineTraceTestActorCollisionChannel.h"
#include "ELineTraceTestActorObjectTypeQuery.h"
#include "ELineTraceTestActorQueryMobilityType.h"
#include "ELineTraceTestActorTraceType.h"
#include "LineTraceTestActor.generated.h"

UCLASS(Blueprintable)
class ALineTraceTestActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTraceComplex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELineTraceTestActorQueryMobilityType QueryMobilityType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELineTraceTestActorTraceType LineTraceBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELineTraceTestActorCollisionChannel SelectedChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELineTraceTestActorObjectTypeQuery SelectedObjectType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SelectedProfileName;
    
    ALineTraceTestActor(const FObjectInitializer& ObjectInitializer);
};

