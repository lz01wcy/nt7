FROM fluffos/fluffos:latest
COPY src /nt7/
COPY config.ini /nt7/config

EXPOSE 5555
EXPOSE 6666
EXPOSE 8888

ENTRYPOINT ["/fluffos/bin/driver"]
CMD ["/nt7/config"]
