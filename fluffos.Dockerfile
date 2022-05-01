FROM fluffos/fluffos:latest
COPY src /nt7/
COPY config.ini /nt7/config

ENTRYPOINT ["/fluffos/bin/driver"]
CMD ["/nt7/config"]
